# This library was made for the program based on this (https://pymotw.com/2/multiprocessing/basics.html)
    # multiprocessing tutorial I found called multiprocess_test.py.

import multiprocessing, time, sys

def worker():
    name = multiprocessing.current_process().name
    print(name, 'Starting')
    time.sleep(2)
    print(name, 'Exiting')

def my_service():
    name = multiprocessing.current_process().name
    print(name, 'Starting')
    time.sleep(3)
    print(name, 'Exiting')

def daemon_test():
    p = multiprocessing.current_process()
    print('Starting:',p.name, p.pid)
    sys.stdout.flush()
    time.sleep(2)
    print('Exiting:',p.name, p.pid)
    sys.stdout.flush()

def non_daemon_test():
    p = multiprocessing.current_process()
    print('Starting:',p.name, p.pid)
    sys.stdout.flush()
    time.sleep(2)
    print('Exiting:',p.name, p.pid)
    sys.stdout.flush()

def slow_worker():
    print('Starting slow_worker')
    time.sleep(0.1)
    print('Finished slow_worker')

def exit_error():
    sys.exit(1)

def exit_ok():
    return

def return_value():
    return 1

def raises():
    raise RuntimeError('There was an error!')

def terminated():
    time.sleep(3)