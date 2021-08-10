# This program was made for this (https://pymotw.com/2/multiprocessing/basics.html) tutorial.
 # It requires the library file multiprocessing_import_worker.py file to work.

 # ----- I CHANGED THE TABBING FORMAT, SO MAKE SURE THERE AREN'T ANY SPACES BREAKING THIS -----

import multiprocessing, time
import multiprocessing_import_worker # Custom library

if __name__ == '__main__':
    import_worker = multiprocessing_import_worker

    # ----- MULTIPROCESSING BASICS -----
    # service = multiprocessing.Process(name='my_service', target=import_worker.my_service)
    # worker_1 = multiprocessing.Process(name='worker_1', target=import_worker.worker)
    # worker_2 = multiprocessing.Process(target=import_worker.worker) # Uses default name
    #
    # worker_1.start()
    # worker_2.start()
    #   service.start()
    # -----         -----

    # ----- DAEMON PROCESSES -----
    d = multiprocessing.Process(name='daemon_test', target=import_worker.daemon_test)
    d.daemon = True

    n = multiprocessing.Process(name='non_daemon_test', target=import_worker.non_daemon_test)
    n.daemon = False

    # ----- WAITING FOR A PROCESS -----
     # Unless a join() statement is given,
        # daemon_test will never exit, because the program quits before the proccess is finished
        # hence why it is daemon. It is meant to do that.
    d.start()
    #time.sleep(1)
    n.start()
    # -----         -----

     #d.join() # This join statment will force the program to stay open until the process finishes
     #n.join()
    # -----         -----

     #d.start()
     #n.start()
     #
     #d.join(1) # Passing a float to join(x) will make the program wait x seconds before killing the process
     #print('d.is_alive()', d.is_alive())
     #n.join()
    # -----         -----

    # ----- TERMINATING A PROCESS -----
     #p = multiprocessing.Process(target=import_worker.slow_worker)
     #print ('BEFORE:', p, p.is_alive())
     #
     #p.start()
     #print('DURING:', p, p.is_alive())
     #
     #p.terminate()
     #print('TERMINATED:', p, p.is_alive()) # The process will will be alive for shortly after the command is given
 #
 ## "It is important to join() the process after terminating it
 # # in order to give the background machinery time to update the status
 # # of the object to reflect the termination."
     #p.join()
     #print ('JOINED:', p, p.is_alive())
# -----         -----

# ----- PROCESS EXIT STATUS -----
 # THIS WILL GIVE AN ERROR. YOU ARE LOOKING FOR THE ERROR CODE!
    jobs = []
    for f in [import_worker.exit_error, import_worker.exit_ok, import_worker.return_value, import_worker.raises, import_worker.terminated]:
        print('Starting process for', f.__name__) # Tutorial uses f.func_name, but that was removed. __name__ works though.
        j = multiprocessing.Process(target=f, name=f.__name__)
        jobs.append(j)
        j.start()

    jobs[-1].terminate()

    for j in jobs:
        j.join()
        print ('%s.exitcode = %s' % j.name, j.exitcode)
# -----         -----