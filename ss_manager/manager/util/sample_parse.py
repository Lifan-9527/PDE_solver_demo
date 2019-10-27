# uuid, Name, authen, serverIP, serverPort, passwd

class sample(object):
	def __init__(self, uuid=None, name=None, authen=None, serverIP=None, serverPort=None, passwd=None):
		self.uuid = uuid
		self.name = name
		self.authen = authen
		self.serverIP = serverIP
		self.serverPort = serverPort
		self.passwd = passwd
		self.IsLegal = False
	
	def toString(self):
		line = str(self.uuid)+'\t'+self.name+'\t'+str(self.authen)+'\t'+self.serverIP+'\t'+self.serverPort+'\t'+self.passwd
		return line

	def parse_from_string(self, line):
		sp_line = line.split('\t')
		self.uuid = int(sp_line[0])
		self.name = sp_line[1]
		self.authen = bool(sp_line[2])
		self.serverIP = sp_line[3]
		self.serverPort = sp_line[4]
		self.passwd = sp_line[5].strip('\n')
	
	def check(self):
		assert isinstance(self.uuid, int), "The uuid (1st element) is not integer."
		assert (self.uuid > 10**10 and  self.uuid < 10**11), "The uuid (1st element) must be formed with [1-9] in 10 digits."
		assert isinstance(self.name, str), "Invalid name (2), please input a string."
		assert isinstance(self.authen, bool), "Invalid authen (3), select from True or False."
