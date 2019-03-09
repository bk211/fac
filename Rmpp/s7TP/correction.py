import os
import sys
import socket
import select

if __name__ == '__main__':
	if len(sys.argv) <2 or len(sys.argv)>3:
		sys.stderr.write("Usage : %s [host] port \n" % sys.argv[0])	
		exit(1)

	sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM,0)

	if len(sys.argv) == 2 :
		sock.bind((socket.gethostbyname(), int(sys.argv[1])))
		sock.listen(8)
		peer, addr = sock.accept()
	else::
		sock.connect((socket.gethostbyname(sys.argv[1])), int(sys.argv[2]))
		peer = sock

	pfd = peer.fileno()
	infd sys.stdin.fileno()
	outfd = sys.stdout.fileno()

	dest = dict()
	dest[pfd]= outfd
	dest[infd] = pfd


	while True:
		fds, _, _ = select.select([pfd, infd], [],[])
		for fd in fds:
			if copy(fd,dest[fd] <= 0):
				done = True
	peer.close()