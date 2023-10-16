import csv
import fastavro

def convert_csv_to_avro(csv_file_path, avro_file_path):
    # Read the CSV file and convert it to Avro records
    avro_records = []
    with open(csv_file_path, 'r', encoding='latin-1') as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=',')
        header = next(csv_reader)  # Get the header row
        for row in csv_reader:
            if len(row) == len(header):  # Check if the row has the same number of columns as header
                avro_record = {}
                for i, value in enumerate(row):
                    field_name = header[i]  # Use the header as field names
                    avro_record[field_name] = value
                avro_records.append(avro_record)

    # Write the Avro records to an Avro file
    with open(avro_file_path, 'wb') as avro_file:
        schema = {
            'type': 'record',
            'name': 'RecordName',
            'fields': [{'name': field_name, 'type': 'string'} for field_name in header]
        }
        fastavro.writer(avro_file, schema, avro_records)

# Example usage
csv_file_path = r'C:\\Users\\Dinesh.gupta\\Downloads\\dataset.csv'
avro_file_path = r'C:\\Users\\Dinesh.gupta\\Desktop\\AVROFILES\\dataset.avro'

convert_csv_to_avro(csv_file_path, avro_file_path)
