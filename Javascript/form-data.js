export const objectToFormData = (obj) => {
  const formData = new FormData();

  for (const key in obj) {
    if (obj.hasOwnProperty(key)) {
      const value = obj[key];

      // Check if the value is a File or Blob, as FormData handles these automatically.
      if (value instanceof File || value instanceof Blob) {
        formData.append(key, value);
      } else if (Array.isArray(value)) {
        // If the value is an array, you may want to handle it differently based on your use case.
        value.forEach((item, index) => {
          formData.append(`${key}[${index}]`, item);
        });
      } else {
        formData.append(key, value);
      }
    }
  }

  return formData;
};

export const logFormData = (formData) => {
  const formDataArray = [];
  for (const [key, value] of formData.entries()) {
    formDataArray.push({ key, value });
  }

  console.log(formDataArray);
};
