<template>
  <div class="container">
    <table class="table mt-4">
      <thead class="table-dark">
      <tr>
        <th>ID</th>
        <th>Name</th>
        <th>Email</th>
        <th>Gender</th>
        <th>Actions</th>
      </tr>
      </thead>
      <tbody>
      <tr v-for="student in students" :key="student.id">
        <td>{{student.id}}</td>
        <td>{{student.first_name}} {{student.last_name}}</td>
        <td>{{student.email}}</td>
        <td>{{student.gender}}</td>
        <td>
          <router-link :to="`/student/${student.id}`" class="btn btn-primary btn-sm me-1">Details</router-link>
          <router-link :to="`/student/edit/${student.id}`" class="btn btn-success btn-sm me-1">Edit</router-link>
          <button class="btn btn-danger btn-sm me-1" @click="deleteStudent(student.id)">Delete</button>
        </td>
      </tr>
      </tbody>
    </table>
  </div>
</template>

<script>
import axios from 'axios'
export default {
  name: "AllStudents",
  data(){
    return{
      students:[],
    }
  },
  created() {
    this.getAllStudents()
  },
  methods:{
    async getAllStudents(){
      await axios.get("http://localhost:5500/students")
      .then((response)=>{
        this.students=response.data
      })
      .catch((err)=>{
        console.log(err)
      })
    },
    deleteStudent(id){
      axios.delete(`http://localhost:5500/Students/${id}`)
          .then(()=>{
            this.getAllStudents()

          })
    }
  }
}
</script>

<style scoped>

</style>