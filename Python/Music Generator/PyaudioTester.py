import pyaudio
import numpy as np
import msvcrt

p = pyaudio.PyAudio()

volume = 0.5     # range [0.0, 1.0]
fs = 44100       # sampling rate, Hz, must be integer
duration = 1.0   # in seconds, may be float
f = 440.0        # sine frequency, Hz, may be float

# generate samples, note conversion to float32 array
A3 = (np.sin(2*np.pi*np.arange(fs*duration)*f/fs)).astype(np.float32)
A2 = (np.sin(2*np.pi*np.arange(fs*duration)*(f/2)/fs)).astype(np.float32)
# for paFloat32 sample values must be in range [-1.0, 1.0]
stream = p.open(format=pyaudio.paFloat32,
                channels=1,
                rate=fs,
                output=True)

# play. May repeat with different volume values (if done interactively)
while True:
    KP = ord(msvcrt.getch())
    print (KP)
    if KP == 97: #if a
        stream.write(A3)

    elif KP == 115: #if s
        stream.write(A2)

    elif KP == 113: #if q v
        exit(0)

stream.stop_stream()
stream.close()

p.terminate()

