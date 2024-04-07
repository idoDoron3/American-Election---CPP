Ass5: main.o RepublicSocialPolitician.o RepublicLeaderPolitician.o DemocraticSocialPolitician.o DemocraticLeaderPolitician.o Politician.o Party.o PoliticalSys.o RepublicParty.o DemocraticParty.o
	g++ main.o RepublicSocialPolitician.o RepublicLeaderPolitician.o DemocraticSocialPolitician.o DemocraticLeaderPolitician.o Politician.o Party.o PoliticalSys.o RepublicParty.o DemocraticParty.o -o Ass5	
DemocraticLeaderPolitician.o: DemocraticLeaderPolitician.cpp DemocraticLeaderPolitician.h Politician.h Defs.h Party.h
	g++ -c DemocraticLeaderPolitician.cpp
DemocraticParty.o: DemocraticParty.cpp DemocraticParty.h Party.h Defs.h Politician.h
	g++ -c DemocraticParty.cpp
DemocraticSocialPolitician.o: DemocraticSocialPolitician.cpp DemocraticSocialPolitician.h Politician.h Defs.h Party.h
	g++ -c DemocraticSocialPolitician.cpp
main.o: main.cpp PoliticalSys.h Defs.h RepublicParty.h Party.h Politician.h DemocraticParty.h RepublicLeaderPolitician.h RepublicSocialPolitician.h DemocraticLeaderPolitician.h DemocraticSocialPolitician.h Exception.h
	g++ -c main.cpp
Party.o: Party.cpp Party.h Defs.h Politician.h
	g++ -c Party.cpp
PoliticalSys.o: PoliticalSys.cpp PoliticalSys.h Defs.h RepublicParty.h Party.h Politician.h DemocraticParty.h RepublicLeaderPolitician.h RepublicSocialPolitician.h DemocraticLeaderPolitician.h DemocraticSocialPolitician.h Exception.h
	g++ -c PoliticalSys.cpp
Politician.o: Politician.cpp Politician.h Defs.h Party.h
	g++ -c Politician.cpp
RepublicLeaderPolitician.o: RepublicLeaderPolitician.cpp RepublicLeaderPolitician.h Politician.h Defs.h Party.h
	g++ -c RepublicLeaderPolitician.cpp
RepublicParty.o: RepublicParty.cpp RepublicParty.h Party.h Defs.h Politician.h
	g++ -c RepublicParty.cpp
RepublicSocialPolitician.o: RepublicSocialPolitician.cpp RepublicSocialPolitician.h Politician.h Defs.h Party.h
	g++ -c RepublicSocialPolitician.cpp

