class test(object):
	"""docstring for test"""
	def __init__(self, b):
		super(test, self).__init__()
		self.a = b
	def get(self):
		return self.a
test_dict = {"wd" : test(100)}

print(test_dict["wd"].a)
print(test_dict["wd"].get())