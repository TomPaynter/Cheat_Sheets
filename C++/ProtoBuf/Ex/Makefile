CC := clang++

main: main.cpp can.pb.cc can.pb.h
	$(CC) -o main main.cpp can.pb.cc -lprotobuf

can.pb.cc can.pb.h: can.proto
	protoc -I=. --cpp_out=. $<

clean:
	$(RM) main 
	$(RM) can.pb.*
	$(RM) *.o

.PHONY: clean

