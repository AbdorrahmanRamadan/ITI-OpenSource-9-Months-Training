const Department=require("./Models/DepartmentSchema")

const departmentsSeeder = [
  { _id: 100, name: "os", location: "alex" },
  { _id: 102, name: "pd", location: "alex" },
  { _id: 101, name: "OS", location: "cairo" },
  { _id: 103, name: "web", location: "aswan" },
  { _id: 105, name: "cloud", location: "alex" },
  { _id: 106, name: "mobile", location: "mansora" },
  { _id: 107, name: "sys-admin", location: "alex" },
  { _id: 108, name: "Ai", location: "smartV" },
];
const seedDb = async() => {
  console.log("seedre file");
await Department.deleteMany({});
await Department.insertMany(departmentsSeeder)

};

module.exports = seedDb;
