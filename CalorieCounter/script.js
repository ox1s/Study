const calorieCounter = document.getElementById("calorie-counter");
const budgetNumberInput = document.getElementById("budget");
const entryDropdown = document.getElementById("entry-dropdown");
const addEntryButton = document.getElementById("add-entry");
const clearButton = document.getElementById("clear");
const output = document.getElementById("output");
let isError = false;

const cleanInputString = (str) => str.replace(/[+-\s]/g, "");
const isInvalidInput = (str) => str.match(/\d+e\d/i);
const addEntry = () => {
    const targetInputContainer = document.querySelector(`#${entryDropdown.value} .input-container`);
    const entryNumber = targetInputContainer.querySelectorAll('input[type="text"]').length + 1;
    const HTMLString = `
    <label for="${entryDropdown.value}-${entryNumber}-name">Entry ${entryNumber} Name</label>
    <input type="text" id="${entryDropdown.value}-${entryNumber}-name" placeholder="Name">
    <label for="${entryDropdown.value}-${entryNumber}-calories">Entry ${entryNumber} Calories</label>
    <input type="number" id="${entryDropdown.value}-${entryNumber}-calories" placeholder="Calories" min="0">
    `;
    targetInputContainer.insertAdjacentHTML("beforeend", HTMLString);
};
const calculateCalories = (e) => {
    e.preventDefault();
    isError = false;
    const breakfastNumberInputs = document.querySelectorAll(`#breakfast input[type='number']`);
    const lunchNumberInputs = document.querySelectorAll(`#lunch input[type='number']`);
    const dinnerNumberInputs = document.querySelectorAll(`#dinner input[type='number']`);
    const snacksNumberInputs = document.querySelectorAll(`#snacks input[type='number']`);
    const exerciseNumberInputs = document.querySelectorAll(`#exercise input[type='number']`);
    const breakfastCalories = getCaloriesFromInputs(breakfastNumberInputs);
    const lunchCalories = getCaloriesFromInputs(lunchNumberInputs);
    const dinnerCalories = getCaloriesFromInputs(dinnerNumberInputs);
    const snacksCalories = getCaloriesFromInputs(snacksNumberInputs);
    const exerciseCalories = getCaloriesFromInputs(exerciseNumberInputs);
};
const getCaloriesFromInputs = (list) => {
    let calories = 0;
    for (const item of list) {
        const currVal = cleanInputString(item.value);
        const invalidInputMatch = isInvalidInput(currVal);
        if (invalidInputMatch) {
            alert(`Invalid Input: ${invalidInputMatch[0]}`);
            isError = true;
            return null;
        }
        calories += Number(currVal);
    }
    return calories;
};
addEntryButton.addEventListener("click", addEntry);

