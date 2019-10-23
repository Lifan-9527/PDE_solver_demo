import table

s = table.table()
s.get_ctx_fromfile("data_test.txt")
s.export()
s.remove(2515151255)
s.export()
s.write_tofile("data_test.txt")
