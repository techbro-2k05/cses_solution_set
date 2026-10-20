""" A script for downloading all your submitted and accepted problems from
the cses.fi competitive programming online judge. Running the script will
download the latest submissions for all solved problems from the CSES Problemset
(even if the latest submission isn't the one that is accepted).

Tested only on the CSES Problemset, although it may work on other CSES contests
(may require some modifications).

Have a nice day!
"""

import os
from urllib.parse import urljoin
from bs4 import BeautifulSoup   # pip install beautifulsoup4
import requests                 # pip install requests


# We scrape the code directly from the html, so there is no way for as
# to identify what file extension to attach to it. So I just assumed cpp 😀
OUT = 'cses-downloads/{UID}-{NAME}.cpp'


def slug(s: str) -> str:
    return s.lower().replace(' ', '-')


def login(user: str, password: str) -> requests.Session:

    s = requests.Session()
    LOGIN_URL = 'https://cses.fi/login/'

    # get login csrf token
    r = s.get(LOGIN_URL)
    soup = BeautifulSoup(r.text, 'lxml')
    field = soup.find('input', {'name': 'csrf_token'})
    csrf = field['value']

    r = s.post(
        url=LOGIN_URL,
        data={
            'csrf_token': csrf,
            'nick': user,
            'pass': password,
        },
    )

    if not r.history:
        # if not redirected to home page after login
        print('🛑 Invalid username or password. Aborting.')
        exit(1)

    return s


def download_submission(s: requests.Session, url: str) -> None:
    soup = BeautifulSoup(s.get(url).text, 'lxml')
    code = soup.find('pre', {'class': 'linenums'}).text
    content = soup.find('div', {'class': 'content'})

    problem_url = urljoin(url, content.find('a')['href'])
    uid = problem_url.split('/')[-2]

    name = soup.find('h1').text

    path = OUT.format(UID=uid, NAME=slug(name))
    with open(path, 'w') as f:
        f.write(code)

    print(f'✅ {name} 👉️ {path}')


def download_problem(s: requests.Session, url: str) -> None:
    soup = BeautifulSoup(s.get(url).text, 'lxml')
    title = soup.find_all('h4')[-1]
    link = title.find_next_sibling('a')
    download_submission(s, urljoin(url, link['href']))


def download_set(s: requests.Session, url: str) -> None:
    soup = BeautifulSoup(s.get(url).text, 'lxml')
    marks = soup.find_all('span', {'class': 'task-score icon full'})
    for mark in marks:
        link = mark.find_previous_sibling('a')
        download_problem(s, urljoin(url, link['href']))


if __name__ == '__main__':
    os.makedirs(os.path.dirname(OUT), exist_ok=True)
    s = login(input('username: '), input('password: '))
    download_set(s, 'https://cses.fi/problemset/list/')

