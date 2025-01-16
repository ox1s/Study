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
    if (hasPlayerWonTheRound(userOption, getRandomComputerResult())) {
        playerScore++;
        return `Player wins! ${userOption} beats ${computerResult}`;
    }
    else if (!hasPlayerWonTheRound(userOption, getRandomComputerResult())) {
        computerScore++;
        return `Computer wins! ${computerResult} beats ${userOption}`;
    }
    else
        return `It's a tie! Both chose ${userOption}`;
}
