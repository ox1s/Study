function getAverage(scores) {
  let sum = 0;

  for (const score of scores) {
    sum += score;
  }

  return sum / scores.length;
}

function getGrade(score) {
  if (score === 100) {
    return "A++";
  } else if (score >= 90) {
    return "A";
  } else if (score >= 80) {
    return "B";
  } else if (score >= 70) {
    return "C";
  } else if (score >= 60) {
    return "D";
  } else {
    return "F";
  }
}

function hasPassingGrade(score) {
  return getGrade(score) !== "F";
}

function studentMsg(totalScores, studentScore) {
  return `Class average: ${ Math.round(getAverage(totalScores) * 10) / 10}. Your grade: ${getGrade(studentScore)}. You ${hasPassingGrade(studentScore) ? "passed" : "failed"} the course.`;
}

function fillArrayWithRandomNumbers(length, min, max) {
  const randomNumbers = [];

  for (let i = 0; i < length; i++) {
    const randomNumber = Math.floor(Math.random() * (max - min + 1)) + min;
    randomNumbers.push(randomNumber);
  }

  return randomNumbers;
}
console.log(studentMsg(fillArrayWithRandomNumbers(7,1,100), 73));

