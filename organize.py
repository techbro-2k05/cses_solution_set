# this script allows organizing the downloaded solutions into problem categories based on the CSES Problemset structure. It fetches the problem categories from the CSES website and moves the downloaded solution files into corresponding category folders.
import re
import shutil
from pathlib import Path

import requests
from bs4 import BeautifulSoup

BASE_DIR = Path(__file__).parent
SOLUTIONS_DIR = BASE_DIR / "cses-downloads"
CSES_URL = "https://cses.fi/problemset/list/"

CATEGORIES = {
    "Introductory Problems",
    "Sorting and Searching",
    "Dynamic Programming",
    "Graph Algorithms",
    "Range Queries",
    "Tree Algorithms",
    "Mathematics",
    "String Algorithms",
    "Geometry",
    "Advanced Techniques",
    "Additional Problems",
    "Sliding Window Problems",
    "Interactive Problems",
    "Bitwise Operations",
}

def normalize(text):
    return re.sub(r"[^a-z0-9]", "", text.lower())


def fetch_problem_categories():
    response = requests.get(CSES_URL, timeout=30)
    response.raise_for_status()
    soup = BeautifulSoup(response.text, "lxml")

    by_id = {}
    by_title = {}
    category = None

    for element in soup.find_all(["h1", "h2", "h3", "h4", "a"]):
        if element.name.startswith("h"):
            heading = element.get_text(" ", strip=True)
            if heading in CATEGORIES:
                category = heading
            continue

        if category is None:
            continue

        match = re.search(
            r"/problemset/task/(\d+)",
            element.get("href", "")
        )
        if match:
            problem_id = match.group(1)
            title = element.get_text(" ", strip=True)
            by_id[problem_id] = category
            by_title[normalize(title)] = category

    if not by_id:
        raise RuntimeError(
            "No problems found. Check the CSES page structure."
        )

    print(f"Found {len(by_id)} problems.")
    return by_id, by_title


def organize():
    if not SOLUTIONS_DIR.is_dir():
        raise FileNotFoundError(
            f"Folder not found: {SOLUTIONS_DIR}"
        )

    by_id, by_title = fetch_problem_categories()
    moved = 0
    unknown = []

    # Only process files directly inside cses-downloads.
    for file in SOLUTIONS_DIR.glob("*.cpp"):
        category = None

        # Supports names such as 1068.cpp or
        # 1068_Weird_Algorithm.cpp.
        match = re.match(r"^(\d+)(?:\D|$)", file.stem)
        if match:
            category = by_id.get(match.group(1))

        # Fallback for files named after the problem.
        if category is None:
            category = by_title.get(normalize(file.stem))

        if category is None:
            unknown.append(file.name)
            continue

        target_dir = SOLUTIONS_DIR / category
        target_dir.mkdir(exist_ok=True)

        target = target_dir / file.name

        if target.exists():
            print(f"SKIPPED existing file: {target}")
            continue

        shutil.move(str(file), str(target))
        print(f"{file.name} -> {category}")
        moved += 1

    print(f"\nDone. Moved {moved} files.")

    if unknown:
        print("\nCould not classify:")
        for filename in unknown:
            print(" -", filename)


if __name__ == "__main__":
    organize()
