
while True:
	try:
		height = int(input("Height: "))
		if height > 0 and height < 9:
			for i in range(1, height + 1):
				space = " " * (height - i)
				hashes = "#" * i
				print(space + hashes)
			break
		elif height <= 0:
			print("INVALID INPUT USE NUMBER HIGHER THAN 0 AND NOT NEGATIVE")
		else:
			print("INVALID USE ONLY LESS THAN 9")
	except ValueError:
		print("INVALID TYPE ONLY USE NUMBERS")
