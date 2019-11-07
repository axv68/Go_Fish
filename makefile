final: card_demo.o player.o deck.o card.o
	g++ -o gofish card_demo.o player.o deck.o card.o
driver: card_demo.cpp player.h deck.h
	g++ -c card_demo.cpp 
player.o: player.cpp player.h deck.h
	g++ -c player.cpp
deck.o: deck.cpp deck.h card.h
	g++ -c deck.cpp
card.o: card.cpp card.h
	g++ -c card.cpp

# final: UtPodDriver.o UtPod.o Song.o
# 	g++ -o utpod UtPodDriver.o UtPod.o Song.o
# driver: UtPodDriver.cpp UtPod.h Song.h
# 	g++ -c UtPodDriver.cpp
# UtPod.o: UtPod.cpp UtPod.h Song.h
# 	g++ -c UtPod.cpp
# Song.o: Song.cpp Song.h
# 	g++ -c Song.cpp