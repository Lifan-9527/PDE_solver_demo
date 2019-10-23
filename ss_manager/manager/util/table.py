try:
	from sample_parse import sample
except:
	from .sample_parse import sample

class table(object):
	def __init__(self, nrow=0, ncol=6):
		self.num = 0
		self.ctx = []

	def write_tofile(self, filename):
		f = open(filename, 'w+')
		if(len(self.ctx)==0): return
		for i in range(len(self.ctx)):
			line = self.ctx[i].toString()
				f.write(line)
				f.write(line)
		f.close()

	def append_tofile(self, filename):
		f = open(filename, 'a+')
		if(len(self.ctx)==0): return
		for i in range(len(self.ctx)):
			line = self.ctx[i].toString()
			if(i!=len(self.ctx)-1):
				f.write(line+'\n')
			if(i==len(self.ctx)-1):
				f.write(line)
		f.close()

	def get_ctx_fromfile(self, filename):
		f = open(filename, 'r+')
		for line in f:
			print(line)
			s = sample()
			s.parse_from_string(line)
			self.ctx.append(s)
			self.num += 1
		f.close()
	
	def export(self):
		print("total accounts: ", self.num)
		for x in self.ctx:
			print("uuid: {}, name: {}, authen: {}, serverIP: {}, serverPort: {}, passwd: {}".format(x.uuid, x.name, x.authen, x.serverIP, x.serverPort, x.passwd))
			
	def get_uuid_list(self):
		uuids = []
		for x in self.ctx:
			uuids.append(x.uuid)
		return uuids

	def lookup(self, s):
		pass
	
	def insert(self, s):
		pass

	def modify(self, s_origin, s_target):
		pass

	def remove(self, uuid):
		i = 0
		while(i < len(self.ctx)):
			if(uuid==self.ctx[i].uuid):
				self.ctx.pop(i)
				self.num -= 1
				continue
			else:
				i+=1


