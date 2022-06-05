<template>
  <h1>Admins</h1>
  <table class="table">
    <thead>
    <tr>
      <th>Name</th>
      <th>Age</th>
      <th>Address</th>
      <th>Delete</th>
    </tr>
    </thead>
    <tbody>
    <tr v-for="admin in admins" :key="admin.name">
      <td>{{ admin.name }}</td>
      <td>{{ admin.age }}</td>
      <td>{{ admin.address }}</td>
      <td>
        <button @click="$emit('delete',index)">Delete</button>
      </td>
    </tr>
    </tbody>
  </table>
</template>

<script>
export default {
  name: "AdminComponent",
  props: ['admins']
}
</script>

<style>

</style>