import subprocess
import os

curr_dir = os.path.dirname(__file__)

def call_velvex(command, relative_path = ["..", "bin", "parser.exe"]):
    path = ""
    for index in range(len(relative_path)):
        if index != len(relative_path)-1:
            path += relative_path[index] + "\\"
        else: path += relative_path[index]
    compiler_path = os.path.abspath(os.path.join(curr_dir, path)) 
    result = subprocess.run([compiler_path, command], capture_output = True, text = True)
    return result.stdout if result.stdout else result.stderr


