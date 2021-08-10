import random, time, multiprocessing, os
import xml.etree.ElementTree as ET
import bot_systems

if __name__ == '__main__':
    # -----     SELECTING SAVE     -----
    print('-----\t\tSAVES\t\t-----')
    saves = os.listdir('./saves') # Load contents of directory ./saves
    for i in saves:
        print(i) # Print contents of ./saves

    print('NEW GAME')
    load = input('\nLoad which save?: ')

    npc_attributes = []
    if load.lower() == 'new game':
        pass

    else:
        # Gets the contents of XML bots file, sorts it, and stores it in bot_attributes
        file_path = './saves/'+load+'/bot_data.xml'
        root = ET.parse(file_path).getroot() # Parse the xml file, and get data <root>

        for npc in root:
            current_npc = [npc.attrib['npc_id']] # Returns value for npc_id
            for sub_element in npc:
                for grand_child in sub_element:
                    current_npc.append(grand_child.text)
            npc_attributes.append(current_npc)

    # -----     LOADING THE SAVE     -----
    bot_objects = []
    for attributes in npc_attributes:
        bot_objects.append(bot_systems.Bots(attributes[0], attributes[1], attributes[2], attributes[3], attributes[4], attributes[5], attributes[6], attributes[7], attributes[8]))


    print('BOTS LOADED:')
    for obj in bot_objects:
        bot_systems.Bots.get_attr(obj)

    processes = []
    for obj in bot_objects:
        proc_name = 'bot'+str(obj.id)
        processes.append( multiprocessing.Process(name=proc_name, target=bot_systems.Bots.npc_loop, args=(obj,)))

    for proc in processes:
        proc.start()
        print(proc)


    # -----     MAIN GAME LOOP  -----
    game = True
    while game:
        print('----------\t\t----------')
        # Checks hunger. If the return value of eat (stored as func_return) is higher than highest_return, than set the current task to eat.
        for obj in bot_objects:
            func_return = bot_systems.Bots.eat(obj, obj.hunger)
            if func_return > obj.highest_return:
                obj.highest_return = func_return
                obj.task = 1

        for obj in bot_objects:
            func_return = bot_systems.Bots.work(obj, obj.work, obj.motivation)
            if func_return > obj.highest_return:
                obj.highest_return = func_return
                obj.task = 2

        for obj in bot_objects:
            # If bot eats
            if obj.task == 1:
                obj.hunger += random.randint(10, 30)
                if obj.hunger > 100:
                    obj.hunger = 100
                print(obj.f_name, obj.l_name, 'ate some food. hunger =', obj.hunger)
            # If bot works
            elif obj.task ==2:

                print(obj.f_name, obj.l_name, 'went to work. work =', obj.work, '--- motivation =', obj.motivation)
            else:
                print(obj.f_name, obj.l_name, 'did nothing...')
                bot_systems.Bots.get_attr(obj)

        for obj in bot_objects:
            # MODIFIES HUNGER VALUE
            rand_num = random.randint(1,15)
            obj.hunger = obj.hunger-rand_num
            # Resets highest_return for next loop
            obj.highest_return = 0
            # Resets task to 0 (do nothing)
            obj.task = 0

        time.sleep(2)

