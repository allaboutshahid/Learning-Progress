"use strict";

const state = {
    history: []
};

const elements = {
    password: document.getElementById("password"),
    length: document.getElementById("length"),
    lengthValue: document.getElementById("lengthValue"),
    upper: document.getElementById("upper"),
    lower: document.getElementById("lower"),
    numbers: document.getElementById("numbers"),
    symbols: document.getElementById("symbols"),
    result: document.getElementById("result"),
    bar: document.getElementById("bar"),
    history: document.getElementById("history")
};

function generatePassword() {
    const length = Number(elements.length.value);

    let characters = "";

    if (elements.upper.checked) {
        characters += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }

    if (elements.lower.checked) {
        characters += "abcdefghijklmnopqrstuvwxyz";
    }

    if (elements.numbers.checked) {
        characters += "0123456789";
    }

    if (elements.symbols.checked) {
        characters += "!@#$%^&*()_+-=[]{}";
    }

    if (characters.length === 0) {
        alert("Select at least one character type.");
        return;
    }

    let password = "";

    for (let i = 0; i < length; i++) {
        const index = Math.floor(
            Math.random() * characters.length
        );

        password += characters[index];
    }

    elements.password.value = password;

    addToHistory(password);
    checkStrength();
}

function checkStrength() {
    const password = elements.password.value;

    if (!password) {
        elements.result.textContent = "Enter a password";
        elements.bar.style.width = "0%";
        return;
    }

    let score = 0;

    if (password.length >= 8) {
        score++;
    }

    if (password.length >= 12) {
        score++;
    }

    if (/[A-Z]/.test(password)) {
        score++;
    }

    if (/[a-z]/.test(password)) {
        score++;
    }

    if (/[0-9]/.test(password)) {
        score++;
    }

    if (/[^A-Za-z0-9]/.test(password)) {
        score++;
    }

    let strength;

    if (score <= 2) {
        strength = "Weak";
    } else if (score <= 4) {
        strength = "Medium";
    } else {
        strength = "Strong";
    }

    elements.result.textContent =
        "Strength: " + strength;

    elements.bar.style.width =
        ((score / 6) * 100) + "%";
}

function updateLength() {
    elements.lengthValue.textContent =
        elements.length.value;
}

function addToHistory(password) {
    state.history.unshift(password);

    if (state.history.length > 10) {
        state.history.pop();
    }

    renderHistory();
}

function renderHistory() {
    elements.history.innerHTML = "";

    if (state.history.length === 0) {
        elements.history.textContent =
            "No passwords generated yet.";
        return;
    }

    state.history.forEach(function(password) {
        const item = document.createElement("div");

        item.textContent = password;
        item.className = "history-item";

        elements.history.appendChild(item);
    });
}

function copyPassword() {
    const password = elements.password.value;

    if (!password) {
        alert("Generate a password first.");
        return;
    }

    navigator.clipboard.writeText(password)
        .then(function() {
            alert("Password copied!");
        })
        .catch(function() {
            alert("Copy failed. Please copy it manually.");
        });
}

function clearHistory() {
    state.history = [];
    renderHistory();
}

elements.password.addEventListener(
    "input",
    checkStrength
);

elements.length.addEventListener(
    "input",
    updateLength
);

document.getElementById("generate")
    .addEventListener(
        "click",
        generatePassword
    );

document.getElementById("copy")
    .addEventListener(
        "click",
        copyPassword
    );

document.getElementById("clear")
    .addEventListener(
        "click",
        clearHistory
    );

updateLength();
renderHistory();