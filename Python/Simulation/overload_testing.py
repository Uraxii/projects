class Overload:
    # line is a list
    def __init__(self,attributes):
        self.f_name = attributes[0]

bot_data = [['jon', 'jones', 0, 5, 10], ['marge', 'marie', 2, 6, 8]]

bot_objects = []
for attributes in bot_data:
    bot_objects.append(Overload(attributes))

print('Contents of bot object:\n',bot_objects,'\n----------')
print('bot_objects[0].f_name:', bot_objects[0].f_name)