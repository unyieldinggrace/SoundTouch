all:
	g++ -shared -fPIC -I../../include -o libSoundTouchC.so SoundTouchDLL.cpp ../SoundTouch/.libs/libSoundTouchSSE.a -L../SoundTouch/.libs -lSoundTouch

clean:
	rm -f libSoundTouchC.so
	
install:
	cp libSoundTouchC.so /usr/local/lib/libSoundTouchC.so
