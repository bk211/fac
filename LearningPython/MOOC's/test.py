def date_converter(language,date):
	y=date.find('/')
	return date[y:]
print(date_converter(english,'5/11/2017'))