import csv

# Load dataset
def load_dataset(filepath):
    with open(filepath, mode='r') as file:
        reader = csv.DictReader(file)
        return [row for row in reader]

# Predicates
def is_passing(student):
    return int(student['Math']) >= 5 and int(student['CS']) >= 5 and int(student['Eng']) >= 5

def is_high_math(student):
    return int(student['Math']) >= 9

def is_struggling(student):
    return int(student['Math']) < 6 and int(student['CS']) < 6

def improved_in_cs(student):
    return int(student['CS']) > int(student['Math'])

# Universal quantifications
def all_students_passed(dataset):
    return all(is_passing(student) for student in dataset)

def all_students_high_math(dataset):
    return all(int(student['Math']) > 3 for student in dataset)

# Existential quantifications
def exists_high_math(dataset):
    return any(is_high_math(student) for student in dataset)

def exists_improved_in_cs(dataset):
    return any(improved_in_cs(student) for student in dataset)

# Combined/nested statements
def every_student_has_subject_above_6(dataset):
    return all(
        any(int(student[subject]) > 6 for subject in ['Math', 'CS', 'Eng'])
        for student in dataset
    )

def every_student_below_6_in_math_has_subject_above_6(dataset):
    return all(
        any(int(student[subject]) > 6 for subject in ['Math', 'CS', 'Eng'])
        for student in dataset if int(student['Math']) < 6
    )

# Negations
def not_all_students_passed(dataset):
    return not all_students_passed(dataset)

def not_all_students_high_math(dataset):
    return not all_students_high_math(dataset)

def not_exists_high_math(dataset):
    return not exists_high_math(dataset)

def not_exists_improved_in_cs(dataset):
    return not exists_improved_in_cs(dataset)

def not_every_student_has_subject_above_6(dataset):
    return not every_student_has_subject_above_6(dataset)

def not_every_student_below_6_in_math_has_subject_above_6(dataset):
    return not every_student_below_6_in_math_has_subject_above_6(dataset)


# Load dataset
dataset = load_dataset("students.csv")

# Universal quantifications
print("All students passed all subjects:", all_students_passed(dataset))
print("All students have a math score higher than 3:", all_students_high_math(dataset))

# Existential quantifications
print("There exists a student who scored above 9 in math:", exists_high_math(dataset))
print("There exists a student who improved in CS over Math:", exists_improved_in_cs(dataset))

# Combined/nested statements
print("For every student, there exists a subject in which they scored above 6:", every_student_has_subject_above_6(dataset))
print("For every student scoring below 6 in Math, there exists a subject where they scored above 6:", every_student_below_6_in_math_has_subject_above_6(dataset))

# Negations
print("Not all students passed all subjects:", not_all_students_passed(dataset))
print("Not all students have a math score higher than 3:", not_all_students_high_math(dataset))
print("There does not exist a student who scored above 9 in math:", not_exists_high_math(dataset))
print("There does not exist a student who improved in CS over Math:", not_exists_improved_in_cs(dataset))
print("Not every student has a subject in which they scored above 6:", not_every_student_has_subject_above_6(dataset))
print("Not every student scoring below 6 in Math has a subject where they scored above 6:", not_every_student_below_6_in_math_has_subject_above_6(dataset))