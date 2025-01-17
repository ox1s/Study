const getRandomComputerResult = () => {
    const options = ["Rock", "Paper", "Scissors"];
    return options[Math.floor(Math.random() * options.length)];
}

let playerScore = 0;
let computerScore = 0;

const hasPlayerWonTheRound = (player, computer) => {
    (player === "Rock" && computer === "Scissors") ||
        (player === "Scissors" && computer === "Paper") ||
        (player === "Paper" && computer === "Rock")
}

const getRoundResults = (userOption) => {
    const computerResult = getRandomComputerResult();
    if (hasPlayerWonTheRound(userOption, computerResult)) {
        playerScore++;
        return `Player wins! ${userOption} beats ${computerResult}`;
    }
    else if (!hasPlayerWonTheRound(userOption, computerResult)) {
        computerScore++;
        return `Computer wins! ${computerResult} beats ${userOption}`;
    }
    else
        return `It's a tie! Both chose ${userOption}`;
}
const playerScoreSpanElement = document.getElementById("player-score");
const computerScoreSpanElement = document.getElementById("computer-score");
const roundResultsMsg = document.getElementById("results-msg");
const winnerMsgElement = document.getElementById("winner-msg");
const optionsContainer = document.querySelector(".options-container");
const resetGameBtn = document.getElementById("reset-game-btn");

const showResults = userOption => {
    roundResultsMsg.innerText = getRoundResults(userOption);
    computerScoreSpanElement.innerText = computerScore;
    playerScoreSpanElement.innerText = playerScore;

    if (playerScore === 3 || computerScore === 3) {
        resetGameBtn.style.display = "block";
        optionsContainer.style.display = "none";
        if (playerScore === 3)
            winnerMsgElement.innerText = "Player has won the game!";
        else
            winnerMsgElement.innerText = "Computer has won the game!";
    }
};

const resetGame = () => {
    computerScore = 0;
    playerScore = 0;
    computerScoreSpanElement.innerText = computerScore;
    playerScoreSpanElement.innerText = playerScore;
    resetGameBtn.style.display = "none";
    optionsContainer.style.display = "block";
    winnerMsgElement.innerText = "";
    roundResultsMsg.innerText = "";
};

resetGameBtn.addEventListener("click", resetGame);

const rockBtn = document.getElementById("rock-btn");
const paperBtn = document.getElementById("paper-btn");
const scissorsBtn = document.getElementById("scissors-btn");

rockBtn.addEventListener("click", function () {
  showResults("Rock");
});

paperBtn.addEventListener("click", function () {
  showResults("Paper");
});

scissorsBtn.addEventListener("click", function () {
  showResults("Scissors");
});