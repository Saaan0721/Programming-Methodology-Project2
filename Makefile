CC=g++
CFLAGS=--std=c++14 
TARGET=final

$(TARGET):
	$(CC) $(CFLAGS) -o $@ final_skeleton_windows.cpp Screen_manager.cpp Bullet.cpp\
		Enemy.cpp Enemy_1n.cpp Enemy_2r.cpp Enemy_3s.cpp Enemy_4d.cpp Enemy_5a.cpp


clean:
	del $(TARGET).exe
