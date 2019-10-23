import os
import sys
sys.path.append("../")
from util.table import table

data_path = "../../database/database.txt"
new_file = "./source.txt"

database = table()
database.get_ctx_fromfile(data_path)
source = table()
source.get_ctx_fromfile(new_file)

d_uuid_list = database.get_uuid_list()
s_uuid_list = source.get_uuid_list()
print(d_uuid_list)
print(s_uuid_list)

i = 0

#source.append_tofile(data_path)
