<template>
  <div>
      <form @submit.prevent="formHandle" class="d-flex flex-column align-items-center" >
        <label for="name">Name</label>
        <input class="w-25" type="text" name="name" v-model="formValues.name" id="name"><br>
        <label for="age">Age</label>
        <input class="w-25" type="text" name="age" v-model="formValues.age" id="age"><br>
        <label for="address">Address</label>
        <input class="w-25" type="text" name="address" v-model="formValues.address" id="address"><br>
        <div >
        <input type="radio" name="rank" v-model="rank" value="student" id="student">
        <label for="student">Student</label><br>
        <input type="radio" name="rank" value="admin" v-model="rank" id="admin">
        <label for="admin">Admin</label><br>
        </div>
        <input type="submit" value="Add User">
      </form>
    </div>
</template>

<script>
export default {
    name:"FormComponent",
    data(){
        return{
            formValues: {name:"",age:"",address:""},
            rank: ""
        }
    },
    methods: {
        formHandle(e){
        e.preventDefault();
        if(this.rank === "student"){
            this.$emit("student", this.formValues);
        }else if(this.rank === "admin"){
            this.$emit("admin", this.formValues);
        }
        
        }
    },
    emits:['admin','student']

}
</script>

<style scoped>

</style>