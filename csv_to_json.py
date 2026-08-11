import csv
import json
import sys

def csv_to_json(csv_path, json_path):
    with open(csv_path, newline="", encoding="utf-8") as csv_file:
        reader = csv.DictReader(csv_file)
        rows = list(reader)

    with open(json_path, "w", encoding="utf-8") as json_file:
        json.dump(rows, json_file, indent=2)

    print(f"Converted {len(rows)} rows to {json_path}")


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python csv_to_json.py input.csv output.json")
        sys.exit(1)
    csv_to_json(sys.argv[1], sys.argv[2])