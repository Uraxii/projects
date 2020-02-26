
# This program will generate 16 bars of music of a specified time signature and BPM
# Formula for calculating note length in seconds : T = (60/BPM)*(n/RN)
    # So a 16th note in 5/8@110bpm is T = (60/110) * (16/8)

import random


print ("Hello!\nThis program will generate 16 bars of music of a specified time signature and BPM.\nGive it a shot!")

ThirtySecond = {'Name': "ThirtySecond", 'Seconds': 32, 'Value': 1}
Sixteenth = {'Name': "Sixteenth", 'Seconds': 16, 'Value': 2}
Eighth = {'Name': "Eighth", 'Seconds': 8, 'Value': 3}
Fourth = {'Name': "Fourth", 'Seconds': 4, 'Value': 4}
Half = {'Name': "Half", 'Seconds': 2, 'Value': 5}
Whole = {'Name': "Whole", 'Seconds': 1, 'Value': 6}
Dot = {'Name': "Dot",'Modifier': 0.5}

Notes = [ThirtySecond,Sixteenth,Eighth,Fourth,Half,Whole]
Modifiers = [Dot]

#Takes input, parses it by :, and sets them as variables
SubDiv,Beats = map(int,input("Enter a time signature (ex. 4:4): ").split(":"))
BPM = int(input("Enter a BPM: "))
print ("Subdivision:",SubDiv,"Beats:",Beats, "BPM:",BPM)
BPS = (60/BPM)

i = 0
while i < len(Notes):
    if 'Seconds' in Notes[i]:
        Notes[i]['Seconds'] = BPS*(Beats/Notes[i]['Seconds'])
        Notes[i]['Value'] = (Beats*Notes[i]['Value'])
        print(Notes[i].get('Name'),",",Notes[i]['Seconds'],"Seconds,","Value:",Notes[i]['Value'])
    else:
        print(Notes[i].get('Name'), ": No seconds value.")
    i+=1

Total = Beats*Whole['Value']
Bar = []
KillSwitch = 0
Dead = False
while Total > 0:
    RandNote = random.choice(Notes)
    #print("Total:",Total,"RandNote:", RandNote['Name'])

    if 'Value' in RandNote:
        if RandNote['Value'] <= Total:
            Bar.append(RandNote)
            Total=Total-RandNote['Value']
            #print("NoteTotal:",Total)
        else:
            KillSwitch+=1

    if KillSwitch > 4:
        print ("DEAD")
        Dead = True
        break
    LastNote = RandNote

i=0
while i < len(Bar):
    print()

print(Total)