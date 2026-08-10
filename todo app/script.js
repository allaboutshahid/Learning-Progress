const taskInput = document.getElementById("taskInput");
const addBtn = document.getElementById("addBtn");
const taskList = document.getElementById("taskList");
const taskCount = document.getElementById("taskCount");
const clearBtn = document.getElementById("clearBtn");

let tasks = JSON.parse(localStorage.getItem("tasks")) || [];

function saveTasks() {
    localStorage.setItem("tasks", JSON.stringify(tasks));
}

function renderTasks() {
    taskList.innerHTML = "";

    tasks.forEach((task, index) => {

        const li = document.createElement("li");

        li.className = "task";

        if (task.completed) {
            li.classList.add("completed");
        }

        const text = document.createElement("span");

        text.className = "task-text";

        text.textContent = task.text;

        text.addEventListener("click", () => {
            tasks[index].completed = !tasks[index].completed;

            saveTasks();

            renderTasks();
        });

        const deleteButton = document.createElement("button");

        deleteButton.className = "delete-btn";

        deleteButton.textContent = "Delete";

        deleteButton.addEventListener("click", () => {
            tasks.splice(index, 1);

            saveTasks();

            renderTasks();
        });

        li.appendChild(text);

        li.appendChild(deleteButton);

        taskList.appendChild(li);
    });

    updateCounter();
}

function addTask() {
    const text = taskInput.value.trim();

    if (text === "") {
        alert("Please enter a task.");
        return;
    }

    tasks.push({
        text: text,
        completed: false
    });

    taskInput.value = "";

    saveTasks();

    renderTasks();
}

function updateCounter() {
    const remaining = tasks.filter(
        task => !task.completed
    ).length;

    taskCount.textContent =
        `${remaining} ${remaining === 1 ? "task" : "tasks"} remaining`;
}

addBtn.addEventListener("click", addTask);

taskInput.addEventListener("keydown", (event) => {
    if (event.key === "Enter") {
        addTask();
    }
});

clearBtn.addEventListener("click", () => {
    if (tasks.length === 0) return;

    if (confirm("Delete all tasks?")) {
        tasks = [];

        saveTasks();

        renderTasks();
    }
});

renderTasks();