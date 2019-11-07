final: card_demo.o Player.o Deck.o Card.o
	g++ -o gofish card_demo.o Player.o Deck.o Card.o
driver: card_demo.cpp Player.h Deck.h
	g++ -c card_demo.cpp 
Player.o: Player.cpp Player.h Deck.h
	g++ -c Player.cpp
Deck.o: Deck.cpp Deck.h Card.h
	g++ -c Deck.cpp
Card.o: Card.cpp Card.h
	g++ -c Card.cpp

# final: UtPodDriver.o UtPod.o Song.o
# 	g++ -o utpod UtPodDriver.o UtPod.o Song.o
# driver: UtPodDriver.cpp UtPod.h Song.h
# 	g++ -c UtPodDriver.cpp
# UtPod.o: UtPod.cpp UtPod.h Song.h
# 	g++ -c UtPod.cpp
# Song.o: Song.cpp Song.h
# 	g++ -c Song.cpp