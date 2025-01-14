let xp = 0;
let health = 100;
let gold = 250;
let fighting;
let currentWeaponIndex = 0;
let monsterHealth;
let inventory = ["stick"];

const button1 = document.querySelector("#button1");
const button2 = document.querySelector("#button2");
const button3 = document.querySelector("#button3");

const text = document.querySelector("#text");
const xpText = document.querySelector("#xpText");
const healthText = document.querySelector("#healthText");
const goldText = document.querySelector("#goldText");
const monsterStats = document.querySelector("#monsterStats");
const monsterName = document.querySelector("#monsterName");
const monsterHealthText = document.querySelector("#monsterHealth");


const goTown = () => {
    update(locations[0]);
};
const goStore = () => {
    update(locations[1]);
};
const goCave = () => {
    update(locations[2]);
};


const buyHealth = () => {
    if (gold >= 10) {
        gold -= 10;
        health += 10;
        goldText.innerText = gold;
        healthText.innerText = health;
    }
    else {
        text.innerText = "You do not have enough gold to buy health.";
    }
};
const buyWeapon = () => {
    if (currentWeaponIndex < weapons.length - 1) {
        if (gold >= 30) {
            gold -= 30;
            currentWeaponIndex++;
            goldText.innerText = gold;
            let newWeapon = weapons[currentWeaponIndex].name;
            text.innerText = `You now have a you ${newWeapon}.`;
            inventory.push(newWeapon);
            text.innerText += ` In your inventory you have: ${inventory}`;
        }
        else {
            text.innerText = "You do not have enough gold to buy a weapon.";
        }
    }
    else {
        text.innerText = "You already have the most powerful weapon!";
        button2.innerText = "Sell weapon for 15 gold";
        button2.onclick = sellWeapon;
    }
};
const sellWeapon = () => {
    if (inventory.length > 1) {
        gold += 15;
        goldText.innerText = gold;
        let currentWeapon = inventory.shift();
        text.innerText = `You sold a ${currentWeapon}.`;
        text.innerText += ` In your inventory you have: ${inventory}`;
    }
    else {
        text.innerText = "Don't sell your only weapon!";
    }
}


const goFight = () => {
    update(locations[3]);
    monsterHealth = monsters[fighting].health;
    monsterStats.style.display = "block";
    monsterName.innerText = monsters[fighting].name;
    monsterHealthText.innerText = monsterHealth;
};
const fightSlime = () => {
    fighting = 0;
    goFight();
}
const fightBeast = () => {
    fighting = 1;
    goFight();
}
const fightDragon = () => {
    fighting = 2;
    goFight();
}
const attack = () => {
    text.innerText = `The ${monsters[fighting].name} attacks.`;
    text.innerText += ` You attack it with your ${weapons[currentWeaponIndex].name}.`;
    health -= getMonsterAttackValue(monsters[fighting].level);
    if (isMonsterHit())
        monsterHealth -= weapons[currentWeaponIndex].power + Math.floor(Math.random() * xp) + 1;
    else
        text.innerText += " You miss.";
    healthText.innerText = health;
    monsterHealthText.innerText = monsterHealth;
    if (health <= 0) {
        lose();
    }
    else if (monsterHealth <= 0) {
        if (fighting === 2) {
            winGame();
        }
        else {
            defeatMonster();
        }
    }
    if(Math.random() <= .1)
        text.innerText += ` Your ${inventory.pop()} breaks.`;
};
const dodge = () => {
    text.innerText = `You dodged the attack from the ${monsters[fighting].name}`;
};
const getMonsterAttackValue = (level) => {
    const hit = (level * 5) - (Math.floor(Math.random() * xp));
    return hit > 0 ? hit : 0;
};
const isMonsterHit = () => Math.random > .2 || health < 20;
const defeatMonster = () => {
    gold += Math.floor(monsters[fighting].level * 6.7);
    xp += monsters[fighting].level;
    goldText.innerText = gold;
    xpText.innerText = xp;
    update(locations[4]);
};


const update = location => {
    monsterStats.style.display = "none";
    button1.innerText = location["button text"][0];
    button1.onclick = location["button functions"][0];
    button2.innerText = location["button text"][1];
    button2.onclick = location["button functions"][1];
    button3.innerText = location["button text"][2];
    button3.onclick = location["button functions"][2];
    text.innerHTML = location.text;
};
const restart = () => {
    health = 100;
    gold = 50;
    xp = 0;
    currentWeaponIndex = 0;
    inventory = ["stick"];
    goldText.innerText = gold;
    xpText.innerText = xp;
    healthText.innerText = health;
    goTown();
};
const lose = () => {
    update(locations[5]);
};
const winGame = () => {
    update(locations[6]);
};

// initialize game arrays
const locations = [
    {
        name: "town square",
        "button text": ["Go to store", "Go to cave", "Fight dragon"],
        "button functions": [goStore, goCave, fightDragon],
        text: "You are in the town square. You see a sign that says \"Store\"."
    },
    {
        name: "store",
        "button text": ["Buy 10 health (10 gold)", "Buy weapon (30 gold)", "Go to town square"],
        "button functions": [buyHealth, buyWeapon, goTown],
        text: "You enter the store."
    },
    {
        name: "cave",
        "button text": ["Fight slime", "Fight beast", "Go to town square"],
        "button functions": [fightSlime, fightBeast, goTown],
        text: "You enter the cave. You see some monsters."
    },
    {
        name: "fight",
        "button text": ["Attack", "Dodge", "Run"],
        "button functions": [attack, dodge, goTown],
        text: "You are fighting a monster."
    },
    {
        name: "kill monster",
        "button text": ["Go to town square", "Go to town square", "Go to town square"],
        "button functions": [goTown, goTown, goTown],
        text: "The monster screams \"Arg!\" as it dies. You gain experience points and find gold."
    },
    {
        name: "lose",
        "button text": ["REPLAY?", "REPLAY?", "REPLAY?"],
        "button functions": [restart, restart, restart],
        text: "You die. &#x2620;"
    },
    {
        name: "win",
        "button text": ["REPLAY?", "REPLAY?", "REPLAY?"],
        "button functions": [restart, restart, restart],
        text: "You defeat the dragon! YOU WIN THE GAME! &#x1F389;"
    }
];

const weapons = [
    { name: "stick", power: 5 },
    { name: "dagger", power: 30 },
    { name: "claw hammer", power: 50 },
    { name: "sword", power: 100 },
];
const monsters = [
    { name: "slime", level: 2, health: 15 },
    { name: "fanged beast", level: 8, health: 60 },
    { name: "dragon", level: 20, health: 300 },
];

// initialize buttons
button1.onclick = goStore;
button2.onclick = goCave;
button3.onclick = fightDragon;