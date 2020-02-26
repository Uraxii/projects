-----       ROOM MOVEMENT   ------
N = R#+1
S = R#-1
E = R#+maxY
W = R#-maxY

-----       IS BORDER       ------
northBorder = t, (R#+1)%maxY == 0
southBorder = t, R#%maxY == 0
eastBorder = t, R# >= (maxX*maxY)-maxY-1 && R# < maxX*maxY
westBorder = t, R# >= 0 && R# < maxY

