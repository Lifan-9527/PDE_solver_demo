import socket

class proxy(object):
	def __init__(self, l_addr=None, l_port=None, r_addr=None, r_port=None, passwd=None):
		self.l_addr = l_addr
		self.l_port = l_port
		self.r_addr = r_addr
		self.r_port = r_port
		self.passwd = passwd
		#if(self.l_addr and self.l_port and self.r_addr and self.r_port):
		self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
		self.sock.bind((l_addr, l_port))
		print("bind to local: ", l_addr+":"+str(l_port))
		self.sock.connect((r_addr, r_port))
		print("connect to remote", r_addr+":"+str(r_port))
	
	def send_udp(self, content):
		if(self.sock):
			self.sock.send(content)
			print("send content:")
			print(content)
		else:
			print("None available socket.")
	
	def udp_add(self):
		cmd = "add: {\"server_port\": "+str(self.r_port)+", \"password\": \""+self.passwd+"\"}"
		content = bytes(cmd, encoding="utf8")
		self.send_udp(content)

	def udp_remove(self):
		cmd = "remove: {\"server_port\": "+str(self.r_port)+", \"passwd\": \""+self.passwd+"\"}"
		content = bytes(cmd, encoding="utf8")
		self.send_udp(content)
	
	def get_buffer(self, size=2000):
		return self.sock.recv(size)

	def release(self):
		self.sock.close()
