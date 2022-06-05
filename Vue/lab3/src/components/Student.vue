<template>
  <h1>Students</h1>
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
    <tr v-for="std in students" :key="std.name">
      <td>{{ std.name }}</td>
      <td>{{ std.age }}</td>
      <td>{{ std.address }}</td>
      <td>
        <button @click="$emit('delete',index)">Delete</button>
      </td>
    </tr>
    </tbody>
  </table>
</template>

<script>
export default {
  name: "StudentComponent",
  props: ['students']
}
</script>

<style>

</style>