'''ce programme permet d'estimer le temps nécessaire pour télecharger un fichier '''
def convert_seconds(time):
	count_hour=time//3600
	count_minute=(time-(3600*count_hour))//60
	count_second=(time-(3600*count_hour)-(60*count_minute))
	count_second='%.1f'%count_second
	if count_hour==1:
		y='hour'
	else:y='hours'	
	if count_minute ==1:
		x='minute'	
	else:x='minutes'	
	if count_second==1:
	    z='second'
	else:z='seconds'    
	return '%d %s, %d %s, %s %s' %(count_hour,y,count_minute,x,count_second,z)
def download_time(seize,unit_seize,speed,unit_speed):
	'''format(taille du fichier,unité de la taille du fichier,vitesse de la bande passante,unité de la vitesse)'''
	#remarque pour l'unité de la vitesse,seul l'unité en numérateur est nécessaire,nous sommes en X par secondes 
	# kilobits (kb), kilobytes (kB), megabits (Mb), megabytes (MB),
	# gigabits (Gb), gigabytes (GB) and terabits (Tb), terabytes (TB).
	bits={'kb':2**10,'kB':2**10*8,'Mb':2**20,'MB':2**20*8,'Gb':2**30,'GB':2**30*8,'Tb':2*40,'TB':2*40*8}
	seize_bit=seize*bits[unit_seize]
	speed_bit=speed*bits[unit_speed]
	time=seize_bit/speed_bit*1.0
	return convert_seconds(time)


#Tests
#print (download_time(1024,'kB', 1, 'MB'))
#>>> 0 hours, 0 minutes, 1 second #resultat attendu 

#print (download_time(1024,'kB', 1, 'Mb'))
#>>> 0 hours, 0 minutes, 8 seconds  # 8.0 seconds is also acceptable

#print (download_time(13,'GB', 5.6, 'MB'))
#>>> 0 hours, 39 minutes, 37.1428571429 seconds

#print (download_time(13,'GB', 5.6, 'Mb'))
#>>> 5 hours, 16 minutes, 57.1428571429 seconds

#print (download_time(10,'MB', 2, 'kB'))
#>>> 1 hour, 25 minutes, 20 seconds  # 20.0 seconds is also acceptable

#print (download_time(10,'MB', 2, 'kb'))
#>>> 11 hours, 22 minutes, 40 seconds  # 40.0 seconds is also acceptable

