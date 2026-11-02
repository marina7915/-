from datetime import datetime

date_formats = (
	"%Y-%m-%d", "%Y/%m/%d", "%Y.%m.%d", "%Y%m%d",
	"%d.%m.%Y", "%d/%m/%Y", "%d-%m-%Y", "%d %m %Y",
	"%m/%d/%Y",
	"%B %d, %Y", "%b %d, %Y", "%B %d %Y", "%b %d %Y",
	"%d %B %Y", "%d %b %Y",
)


def parse_date(date_text):
	date_text = date_text.strip()
	for date_format in date_formats:
		try:
			return datetime.strptime(date_text, date_format)
		except ValueError:
			continue
	raise ValueError("Unsupported date format")


name = input("What is your name? ")

while True:
	date_of_birth = input(
		"Date of birth : ")
	try:
		birth_date = parse_date(date_of_birth)
		break
	except ValueError:
		print("Введите дату в другом формате.")

current_date = datetime.now()

current_seconds = current_date.timestamp()
birth_seconds = birth_date.timestamp()

today = datetime.fromtimestamp(current_seconds).date()
birth_day = datetime.fromtimestamp(birth_seconds).date()
years_old = today.year - birth_day.year
if (today.month, today.day) < (birth_day.month, birth_day.day):
	years_old -= 1

print(f'Hello {name}, you are {years_old} years old.')
