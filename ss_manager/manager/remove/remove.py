import os
import sys
import json
import socket
sys.path.append("../")
from util.table import table
from util.proxy import proxy

configFile = open("config.json")
config = json.load(configFile)
data_path = "../../database/database.txt"
rm_file = config["file"]
l_addr = config["local_ip"]
l_port = config["local_port"]


# get rm_list
rm_list = []
with open(rm_file, "r+") as f:
	for line in f:
		rm_list.append(int(line.strip('\n')))

# Database modification
database = table()
database.get_ctx_fromfile(data_path)
print("original database: ")
database.export()
print("remove list: ", rm_list)
d_uuid_list = database.get_uuid_list()

rm_ctxs = database.lookup(rm_list)

# database management
for x in rm_list:
	database.remove(x)
print("new database:")
database.export()
print("---------------")

for x in rm_ctxs:
	remote_addr = x.serverIP
	remote_port = x.serverPort
	passwd = x.passwd
	sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
	sock.bind((l_addr, l_port))
	sock.connect((remote_addr, 6001))
	sock.send(b"ping")
	print(sock.recv(1506))
	cmd = "remove: {\"server_port\": "+str(remote_port)+"}"
	print(cmd)
	content = bytes(cmd, encoding="utf8")
	print(content)
	sock.send(content)
	sock.send(content)
	sock.send(content)
	sock.send(content)
	res = sock.recv(1506)
	print(res)


if(res==b'ok'):
	database.write_tofile(data_path)
	print("successfully remove")
	for x in rm_ctxs:
		print(x.uuid)
else:
	print("fail to remove uuid. Please retry.")
