import multiprocessing, time

class Bots:
    def __init__(self, id, f_name, l_name, hunger, sleep, work, motivation, lawfulness, status):
        self.id = int(id)
        self.f_name = f_name
        self.l_name = l_name
        self.hunger = int(hunger)
        self.sleep = int(sleep)
        self.work = int(work)
        self.motivation = int(motivation)
        self.lawfulness = int(lawfulness)
        self.status = int(status)
        self.highest_return = 0
        self.task = 0

    def get_attr(self):
        """
        Name: get_attr(funct):
            Prints the attributes of an object from the Bots class.
            
        Args:
            # param1: self(object), An object from the Bots class
            
        Returns:
            None
        """
        
        print('id:', self.id, ', f_name:', self.f_name, ', l_name:', self.l_name, ', hunger:', self.hunger, ', sleep:', self.sleep, 'work:', self.work, ', status:', self.status, sep='')
        print("\tMODIFIERS: ",'motivation:', self.motivation, ', lawfulness:', self.lawfulness, sep='')

    def npc_loop(self):
        """
        Name: npc_loop(funct):
            Starts the bots individual process, so everything can run in parrallel.
            
            Args:
                param1: self (object): An object from the Bots class
                
            Returns: 
                None
        """
    
        p = multiprocessing.current_process()
        print('Starting:', p.name, p.pid)
        print(self.f_name)
        print ('Stopping:', p.name)

    def eat(self, hunger):
        """
        Name: eat(funct)
            Returns a value that will help determine when a NPC will eat.
            Greater the value, higher the task priority. Return of 0 means death.
        
        Args:
            param1: self(object)
            param2: hunger(int), hunger level of npc
            
        Returns:
            int: hunder desire value
        """
    
        if hunger >= 90:
            return 10
        elif hunger >= 50:
            return 50
        elif hunger >= 30:
            return 90
        elif hunger >= 1:
            return 100
        else:
            return 0

    def work(self, work, motivation):
        """
        Name: work(funct)
            Function eat will return a value that is used to determine when a NPC will work.
            Greater the number, higher the task priority.
        
        Args:
            param1: self(object), An object from the Bots class
            param2: work(int), work level of npc
            param3: motivation(int), motivation modifier of npc -----   NOT IN USE YET  -----
            
        Returns:
            int: work desire value
        """
        
        if work >= 90:
            return 100
        elif work >= 50:
            return 90
        elif work >= 30:
            return 50
        elif work >= 10:
            return 10
        else:
            return 0


    # Function for the memes
    def unionize(self):
        """
        Name:
        
        Args:
            param1: self(object), an object from the Bots class
        Returns:
            None
        """
    
        print('\n-----\t\t-----\nSHUT THE PLANT DOWN!\n-----\t\t-----')
        quit()