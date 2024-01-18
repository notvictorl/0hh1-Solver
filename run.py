import os

# Commands
compile_cmd = "g++ solver.cpp -std=c++11 -o solver.x"
make_cmd = "make solver.x"
run_cmd = "./solver.x"

# Run
os.system(make_cmd)
os.system(run_cmd)