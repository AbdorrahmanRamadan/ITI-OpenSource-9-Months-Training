<template>
    <div>
      <button class="btn btn-primary col-2 m-5 " @click="choice = 1">Form</button>
      <button class="btn btn-primary col-2 m-5 " @click="choice = 2">Students</button>
      <button class="btn btn-primary col-2 m-5 " @click="choice = 3">Admins</button>
    </div>
    <div>
      <FormComponent  @student="createStudent" @admin="createAdmin" v-if="choice == 1" />
      <StudentComponent v-if="choice == 2" :students="students" @delete="deleteStudent" />
      <AdminComponent v-if="choice == 3" :admins="admins" @delete="deleteAdmin" />
    </div>
</template>

<script>
import AdminComponent from "@/components/Admin";
import FormComponent from "@/components/Form";
import StudentComponent from "@/components/Student";

export default {
  name: 'App',
  components: {
    AdminComponent,
    FormComponent,
    StudentComponent
  },data() {
    return {
      choice: 1,
      students: [],
      admins: []
    }
  },
  methods: {
    createStudent(student) {
      console.log("added" , this.students)
      this.students.push(student)
    },
    createAdmin(admin) {
      this.admins.push(admin)
    },
    deleteStudent(index) {
      this.students.splice(index,1)
    },
    deleteAdmin(index) {
      this.admins.splice(index,1)
    }
  },
}

</script>

<style>
* {
  text-align:center;
}
</style>
