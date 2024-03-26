//Arrays 

const numbers = new Array();
const fruits = ['apples', 'oranges', 'pears'];
console.log(fruits[1]);

//Object literals

const person = {
    firstName: 'John',
    lastName: 'Doe',
    age: 30,
    hobbies: ['music', 'movies', 'sports'],
    address: {
        street: '50 Main St',
        city: 'Boston',
        state: 'MA'
    }
}

const { firstName , lastName, address: {city}} = person;

person.email = "johndoe@gmail.com";

console.log(person.email);

//Arrays of Objects
const todos = [
    {
        id: 1,
        text: 'Take out trash',
        isCompleted: true
    },
    {
        id: 2,
        text: 'Meeting with boss',
        isCompleted: true
    },
    {
        id: 3,
        text: 'Dentist appt',
        isCompleted: false
    },
]

console.log(todos[1].text);