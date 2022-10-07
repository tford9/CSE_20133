import os, stat
import shutil
import subprocess
import sys
import time
from typing import List

import pandas as pd


def get_dirs(dir_path: str, substring_match=None):
    res = []
    for path in os.listdir(dir_path):
        # check if current path is not a file
        if not os.path.isfile(os.path.join(dir_path, path)):
            if substring_match is None:
                res.append(path)
            elif substring_match in path:
                res.append(path)
    return res


def get_student_submissions(pc_name, base_dir):
    # print(pc_name)
    student_dirs = get_dirs(base_dir)
    student_pc_dirs = {}
    for student_dir in student_dirs:
        pc_dir = get_dirs(base_dir + student_dir, pc_name)
        if pc_dir:
            student_pc_dirs[student_dir] = os.path.join(base_dir, student_dir, pc_dir[0])
    return student_pc_dirs


class PC:
    student_pc_dirs = {}
    source_files_expected = []
    prime_directory = ""
    build_directory = './build/'

    def __init__(self, pc_number=2, base_dir: str = './student_challenge_data/'):
        self.pc_name = f'PC{pc_number:02d}'
        self.student_pc_dirs = get_student_submissions(self.pc_name, base_dir)
        self.makefile = self.get_makefile()
        self.prime_directory = os.getcwd()
        if not self.makefile:
            print("No Makefile found")
        print(self.student_pc_dirs.keys())

    def __del__(self):
        self.clear_build_directory()

    def get_makefile(self):
        res = []
        for path in os.listdir(self.build_directory):
            print(os.path.join(self.build_directory, path))
            # check if current path is not a file
            if os.path.isfile(os.path.join(self.build_directory, path)) and 'Makefile' in path:
                res.append(os.path.join(self.build_directory, path))
        return res

    def set_sources(self, source_files_expected: List[str]):
        self.source_files_expected = source_files_expected

    def clear_build_directory(self):
        os.chdir(self.prime_directory)
        files = [f for f in os.listdir(self.build_directory) if not f == 'Makefile']
        for f in files:
            print(f"deleting {os.path.join(self.build_directory, f)}")
            os.remove(os.path.join(self.build_directory, f))

    def test_student_source(self, net_id='abehnlin', source_file_name: str = None, test_cases=None):
        # print(f"Making {net_id}'s {self.pc_name} file: {source_file_name}")
        fail = [0,1]
        self.clear_build_directory()
        try:
            if source_file_name == 'all':
                files = [f for f in os.listdir(self.student_pc_dirs[net_id]) if f.endswith('.c, .h, .cpp, .hpp')]
                for f in files:
                    shutil.copy2(self.student_pc_dirs[net_id] + '/' + f, self.build_directory + '/' + f)

            else:
                shutil.copy2(self.student_pc_dirs[net_id] + '/' + source_file_name,
                             self.build_directory + '/' + source_file_name)
        except Exception as e:
            print(f"Copy Failed: {e}")
            return 0, str(e)
        os.chdir(self.build_directory)

        make_process = subprocess.Popen(['make', 'clean'], stderr=subprocess.STDOUT)
        make_process.wait()

        if source_file_name == 'all':
            make_process = subprocess.Popen(['make', 'all'], stderr=subprocess.STDOUT)
        else:
            cmd = ["make", f"{source_file_name.split('.')[0]}"]
            print(cmd)
            make_process = subprocess.Popen(["make", f"{source_file_name.split('.')[0]}"],
                                            stderr=subprocess.STDOUT)

        if make_process.wait() != 0:
            print('Make Error.')
            return 0, 'Make Error.'
        os.chmod(f"{source_file_name.split('.')[0]}", stat.S_IRWXU)

        # print(f"Making {net_id}'s {self.pc_name} file: {source_file_name} Completed\n\n")

        # print(f"Running {net_id}'s {self.pc_name} file: {source_file_name}")
        cmd = f"./{source_file_name.split('.')[0]}"
        print(cmd)

        tests_passed = 0
        tests_failed = 0

        if test_cases:
            for test_input, test_output in test_cases:
                run_process = subprocess.Popen(cmd,
                                               stdin=subprocess.PIPE,
                                               stdout=subprocess.PIPE,
                                               stderr=subprocess.STDOUT
                                               , encoding='utf-8')
                try:
                    grep_stdout = run_process.communicate(input=test_input, timeout=15)[0]
                except Exception as e:
                    print(e)
                    return 0,str(e)

                if test_output in grep_stdout:
                    # print(
                        # f"Test Succeeded: {test_input}|{test_output} \n {net_id}'s {self.pc_name} file: {source_file_name}")
                    tests_passed += 1
                else:
                    print(
                        f"Test Failed: {test_input}|{test_output} \n {net_id}'s {self.pc_name} file: {source_file_name} \n{grep_stdout}")

                    tests_failed += 1

        os.chdir(self.prime_directory)

        return tests_passed, tests_failed


if __name__ == '__main__':
    pc = PC(pc_number=2)

    test_cases = {'number_scanner.c': [['30\n', "30.00000"], ['2.6\n', "2.6"]],
                  'paycheck.c': [['10\n20\n', "610"], ['40\n40\n', "4883"]],
                  'prog_paycheck.c': [['10\n20\n', "781"], ['12\n38\n', "1761"]],
                  'sphere_volume.c': [['1\n', "4.1"], ['2.7\n', "82.4"]]
                  }

    df = pd.DataFrame(columns=list(['netid', 'pc']+list(test_cases.keys())))
    print(list(['netid', 'pc']+list(test_cases.keys())))
    pc.set_sources(list(test_cases.keys()))

    for net_id in pc.student_pc_dirs.keys():
        user_passes = {}

        for prog in test_cases.keys():
            tests_passed, tests_failed = pc.test_student_source(net_id, source_file_name=prog,
                                                                test_cases=test_cases[prog])

            if isinstance(tests_failed, str):
                user_passes[prog] = tests_failed
            else:
                user_passes[prog] = tests_passed/(tests_failed+tests_passed)*100
            # time.sleep(1)

        user_df = {'netid': net_id, 'pc': pc.pc_name}

        for prog in user_passes.keys():
            user_df[prog] = user_passes[prog]

        user_s = pd.Series(user_df)
        print(user_passes)
        print(user_s)

        df = df.append(user_s.to_frame().T, ignore_index=True)

    print(df)
    df.to_excel('./student_challenge_data/auto_grading.xlsx')
