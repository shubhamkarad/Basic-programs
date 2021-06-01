command = ""
started = False
while True:
	command = input("> ").lower()	
	if command == "start":
		if started:
			print("car is already started")
		else :
			 started = True
		     print("car started... ")
			
	elif command == "stop" :
		print("car stopped")
		
	elif command == "help":
		print("""
start - start the car
stop - stop the car 
quit - quit
			  """)
	elif command == "quit":
		break
		
else:
	 print("sorry !")