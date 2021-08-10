import xml.etree.ElementTree as ET
file_path = './saves/testing/bot_data.xml'
tree = ET.parse(file_path)
root = tree.getroot()

for npc in root:
    print(npc.tag, ':', npc.attrib)
    for sub_child in npc:
        print("\t"+sub_child.tag+"\t")
        for grand_child in sub_child:
            print(grand_child.tag, ':', grand_child.text)
    print("-----\t\t-----")