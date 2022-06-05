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
import {ref} from "vue";
export default {
  name: 'App',
  components: {
    AdminComponent,
    FormComponent,
    StudentComponent
  },
  setup(){
    const choice = ref(1);
    const students= ref([]);
    const admins= ref([]);
    function createStudent(student){
      console.log("added" ,students.value)
      students.value.push(student)
    }
    function createAdmin(admin)
    {admins.value.push(admin)}
    function deleteStudent(index)
    {students.value.splice(index,1)}
    function deleteAdmin(index)
    {admins.value.splice(index,1)}
    return{
      choice,students,admins,createStudent,createAdmin,deleteStudent,deleteAdmin
    }
  },
}

</script>

<style>
* {
  text-align:center;
}
</style>
