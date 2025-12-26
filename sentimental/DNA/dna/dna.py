import csv
import sys


def main():

    # TODO: Check for command-line usage

    if len(sys.argv) != 3:
        print("Error -> Usage: python dna.py database.csv sequence.txt")
        sys.exit(1)

    database = sys.argv[1]
    searchable_squence = sys.argv[2]

    # TODO: Read database file into a variable

    with open(database, "r") as sd:
        # data = csv.reader(sd) # RAW VIEW
        d_reader = csv.DictReader(sd)  # DICTIONARY VIEW
        head_2 = list(d_reader.fieldnames)
        data_subsequence = head_2[1:]  # More optimisaion
        # print(data_subsequence)

  # isolating the names
        names = []
        for row in d_reader:  # Iterate through each row
            names.append(row)
            name = row["name"]  # Access the name
            # print(f"Names: {name}")

# --------------------------------
# DEBUGGING DATA
# --------------------------------

    # ld = open('sentimental/DNA/dna/databases/large.csv', "r")
    # ld_reader = csv.DictReader(ld)  # DICTIONARY VIEW
    # print(ld_reader.fieldnames)

    # Different way to open but its the same so, i am just having fun

     # DATA CHECKING

    # ld_rows =[]
    # for row in ld_reader:
    #     ld_rows.append(row)
    #     print("\n", row)

# --------------------------------
# DEBUGGING DATA
# --------------------------------

    # TODO: Read DNA sequence file into a variable

    with open(searchable_squence, "r") as dna_seq:
        data_sequence = dna_seq.read().strip()

    # print(data_sequence)
    # print(len(data_sequence))

    # TODO: Find longest match of each STR in DNA sequence

    matching_sequence = []  # result

    for subseq in data_subsequence:
        x = longest_match(data_sequence, subseq)
        matching_sequence.append(x)

    # print(matching_sequence)

    # TODO: Check database for matching profiles

    for row in names:
        name = row["name"]  # Access name again during matching its the same as up
        # Convert CSV STR counts to integers for comparison
        row_counts = [int(row[x]) for x in data_subsequence]
        if row_counts == matching_sequence:
            print(f"{name}")
            return
    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches

        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
