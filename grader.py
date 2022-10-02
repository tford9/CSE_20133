import os
import shutil
import subprocess
from typing import List


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


def get_makefile(base_dir: str):
    res = []
    for path in os.listdir(base_dir):
        # check if current path is not a file
        if os.path.isfile(os.path.join(base_dir, path)) and 'Makefile' in path:
            res.append(os.path.join(base_dir, path))
    return res


class PC:
    student_pc_dirs = {}
    source_files_expected = []
    build_directory = './build/'

    def __init__(self, pc_number=2, base_dir: str = './student_challenge_data/'):
        self.pc_name = f'PC{pc_number:02d}'
        self.student_pc_dirs = get_student_submissions(self.pc_name, base_dir)
        self.makefile_dir = get_makefile(base_dir)
        if not self.makefile_dir:
            print("No Makefile found")
        print(self.student_pc_dirs.keys())

    def set_sources(self, source_files_expected: List[str]):
        self.source_files_expected = source_files_expected

    def clear_build_directory(self):
        files = [f for f in os.listdir(self.build_directory) if not f == 'Makefile']
        for f in files:
            print(f"deleting {os.path.join(self.build_directory, f)}")
            os.remove(os.path.join(self.build_directory, f))

    def make_student_source(self, net_id='tford5', source_file_name=None):
        print(f"Making {net_id}'s {self.pc_name} file: {source_file_name}")
        self.clear_build_directory()
        os.chdir(self.build_directory)
        shutil.copy2(self.student_pc_dirs[net_id], self.build_directory)

        if source_file_name == 'all':
            make_process = subprocess.Popen("make clean all", stderr=subprocess.STDOUT)
        else:
            make_process = subprocess.Popen(f"make clean {source_file_name}", stderr=subprocess.STDOUT)

        if make_process.wait() != 0:
            print('Make Error.')


if __name__ == '__main__':
    pc = PC(pc_number=2)
    pc.set_sources(['number_scanner.c', 'paycheck.c', 'prog_paycheck.c', 'sphere_volume.c'])
    exit()
