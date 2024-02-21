import os

# Commands
compile_cmd = "g++ solver.cpp -std=c++11 -o solver.out"
make_cmd = "make solver.out"
run_cmd = "./solver.out"

# Run
os.system(make_cmd)
os.system(run_cmd)