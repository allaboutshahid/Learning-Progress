let students = [];

function addStudent(id, name, marks) {
    students.push({
        id: id,
        name: name,
        marks: marks
    });
    console.log("Student added successfully.");
}

function displayStudents() {
    if (students.length === 0) {
        console.log("No students found.");
        return;
    }

    console.log("\n----- Student List -----");
    students.forEach((student, index) => {
        console.log(`Student ${index + 1}`);
        console.log(`ID: ${student.id}`);
        console.log(`Name: ${student.name}`);
        console.log(`Marks: ${student.marks}`);
        console.log("----------------------");
    });
}

function searchStudent(id) {
    let student = students.find(s => s.id === id);

    if (student) {
        console.log("Student Found:");
        console.log(student);
    } else {
        console.log("Student not found.");
    }
}

function updateMarks(id, newMarks) {
    let student = students.find(s => s.id === id);

    if (student) {
        student.marks = newMarks;
        console.log("Marks updated successfully.");
    } else {
        console.log("Student not found.");
    }
}

function deleteStudent(id) {
    let index = students.findIndex(s => s.id === id);

    if (index !== -1) {
        students.splice(index, 1);
        console.log("Student deleted successfully.");
    } else {
        console.log("Student not found.");
    }
}

function calculateAverage() {
    if (students.length === 0) {
        console.log("No students available.");
        return;
    }

    let total = 0;

    students.forEach(student => {
        total += student.marks;
    });
    let average = total / students.length;
    console.log(`Average Marks: ${average.toFixed(2)}`);
}